/*
 * Copyright (C) 2011 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


package android.filterpacks.imageproc;

import android.filterfw.core.Filter;
import android.filterfw.core.FilterEnvironment;
import android.filterfw.core.Frame;
import android.filterfw.core.FrameFormat;
import android.filterfw.core.NativeProgram;
import android.filterfw.core.NativeFrame;
import android.filterfw.core.Program;
import android.filterfw.core.ShaderProgram;

public class Invert extends Filter {

    private Program mProgram;
    private FrameFormat mOutputFormat;

    private final String mInvertShader =
            "precision mediump float;\n" +
            "uniform sampler2D tex_sampler_0;\n" +
            "varying vec2 v_texcoord;\n" +
            "void main() {\n" +
            "  vec4 color = texture2D(tex_sampler_0, v_texcoord);\n" +
            "  gl_FragColor.r = 1.0 - color.r;\n" +
            "  gl_FragColor.g = 1.0 - color.g;\n" +
            "  gl_FragColor.b = 1.0 - color.b;\n" +
            "}\n";;

    public Invert(String name) {
        super(name);
    }

    public String[] getInputNames() {
        return new String[] { "frame" };
    }

    public String[] getOutputNames() {
        return new String[] { "frame" };
    }

    public boolean setInputFormat(int index, FrameFormat format) {
        if (format.isBinaryDataType() &&
            (format.getTarget() == FrameFormat.TARGET_NATIVE ||
             format.getTarget() == FrameFormat.TARGET_GPU)) {
            mOutputFormat = format;
            return true;
        }
        return false;
    }

    public FrameFormat getFormatForOutput(int index) {
        return mOutputFormat;
    }

    public void prepare(FilterEnvironment environment) {
        switch (mOutputFormat.getTarget()) {
            case FrameFormat.TARGET_NATIVE:
                mProgram = new NativeProgram("filterpack_imageproc", "invert");
                break;

            case FrameFormat.TARGET_GPU:
                mProgram = new ShaderProgram(mInvertShader);
                break;
        }
    }

    public int process(FilterEnvironment env) {
        // Get input frame
        Frame input = pullInput(0);

        // Create output frame
        Frame output = env.getFrameManager().newFrame(mOutputFormat);

        // Process
        mProgram.process(input, output);

        // Push output
        putOutput(0, output);

        // Release pushed frame
        output.release();

        // Wait for next input and free output
        return Filter.STATUS_WAIT_FOR_ALL_INPUTS |
                Filter.STATUS_WAIT_FOR_FREE_OUTPUTS;
    }

}
