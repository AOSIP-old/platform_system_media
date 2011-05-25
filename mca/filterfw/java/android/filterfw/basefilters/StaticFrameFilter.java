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


package android.filterpacks.base;

import android.filterfw.core.Filter;
import android.filterfw.core.FilterEnvironment;
import android.filterfw.core.FilterParameter;
import android.filterfw.core.Frame;
import android.filterfw.core.FrameFormat;
import android.filterfw.core.KeyValueMap;

// TODO: Remove this eventually and replace with frame-independent versions such as ObjectSource.

public class StaticFrameFilter extends Filter {

    @FilterParameter(name = "frame", isOptional = false)
    private Frame mFrame;

    public StaticFrameFilter(String name) {
        super(name);
    }

    public String[] getInputNames() {
        return null;
    }

    public String[] getOutputNames() {
        return new String[] { "frame" };
    }

    public boolean setInputFormat(int index, FrameFormat format) {
        return false;
    }

    public FrameFormat getFormatForOutput(int index) {
        return mFrame.getFormat();
    }

    public int process(FilterEnvironment env) {
        // Push output
        putOutput(0, mFrame);

        // Wait for free output
        return Filter.STATUS_FINISHED;
    }

}
