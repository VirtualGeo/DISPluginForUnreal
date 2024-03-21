set UEDIR=E:\UE_5.2
set UENAME=UE5.2
set ZIP="C:\Program Files\7-Zip\7z.exe"
set PLUGINNAME=GRILLDISForUnreal


if exist Generated (
	rmdir /S /Q Generated
)

call "%UEDIR%\Engine\Build\BatchFiles\RunUAT.bat" BuildPlugin -Rocket -Plugin=%~dp0/%PLUGINNAME%.uplugin -CreateSubFolder -TargetPlatforms=Win64 -Package=%~dp0/Generated/%PLUGINNAME% -archive -clean

call %ZIP% a -t7z %PLUGINNAME%_%UENAME%.7z %~dp0/Generated/%PLUGINNAME%/

pause