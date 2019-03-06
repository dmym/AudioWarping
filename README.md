## Overview
Solution implements sample -> audio time conversion algorithm which is used by Digital Audio Workstations to map audio clip to track tempo

## Solution Structure
Solution consists of three projects:
- AudioWarping - implementation of audio warping logic, compiled as a static library
- AudioWarpingApp - client app for AudioWarping library
- AudioWarpingTest - gtests for AudioWarping library

## External dependencies
AudioWarpingTest project depends on Microsoft.googletest.v140 library