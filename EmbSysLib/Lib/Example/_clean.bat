@echo off

set REP=nul

rem uncomment this, if a report is required:
rem set REP=%cd%/report.txt 2> nul

echo cleaning Example
rmdir /S /Q .\Bin\LPC11Uxx        2>> %REP%
rmdir /S /Q .\Bin\LPC17xx         2>> %REP%
rmdir /S /Q .\Bin\STM32L1xx       2>> %REP%
rmdir /S /Q .\Bin\STM32F4xx       2>> %REP%
rmdir /S /Q .\Bin\Virtual         2>> %REP%
rmdir /S /Q .\Bin                 2>> %REP%

rm .\*.bak           2>> %REP%
rm .\*.dep*          2>> %REP%
rm .\*.axf           2>> %REP%
rm .\*.layout        2>> %REP%
rm .\*.uvgui.*       2>> %REP%
rm .\*.uvopt         2>> %REP%
rm .\main.exe        2>> %REP%
rm .\JLinkLog.txt    2>> %REP%
rm ".\Target 1.bat"  2>> %REP%


rem pause
