@echo off
echo Compiling project...
gcc -o video_render.exe video_render.c vec_3.c sphere.c hittable.c hit_list.c render.c animation.c common.c color.c ray.c intervals.c -lm
if %errorlevel% neq 0 (
    echo Compilation failed!
    pause
    exit /b %errorlevel%
)
echo Compilation successful! video_render.exe created.
pause
