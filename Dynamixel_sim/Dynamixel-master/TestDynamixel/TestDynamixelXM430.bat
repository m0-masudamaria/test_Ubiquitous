@echo off
: Dynamixel�̃e�X�g


:�l�[�~���O�T�[�r�X�̊m�F
rtls /localhost > nul
if errorlevel 1 (
  echo �l�[�~���O�T�[�o��������܂���
  pause
  exit /b 1
  rem /b�I�v�V�����͐e���I��点�Ȃ����߂ɕK�{
)

:�R���|�[�l���g�̋N��
call ..\Dynamixel.bat
start "" TkSliderCommandXM430.pyw
start "" TkSliderSpeedXM430.pyw
start "" TkSliderGainXM430.pyw
start "" TkMonitorSliderPositionXM430.pyw
start "" TkMonitorSliderMoving.pyw

:�R���|�[�l���g����ϐ���
set c=/localhost/TkSliderCommandXM4300.rtc
set s=/localhost/TkSliderSpeedXM4300.rtc
set g=/localhost/TkSliderGainXM4300.rtc
set p=/localhost/TkMonitorSliderPositionXM4300.rtc
set m=/localhost/TkMonitorSliderMoving0.rtc
set d=/localhost/Dynamixel0.rtc

:���ԑ҂�
timeout 10

:�R���t�B�M�����[�V����
rtconf %d% -s xm430 act

:�ڑ�
rtcon %c%:slider %d%:goalPosition
rtcon %s%:slider %d%:movingSpeed
rtcon %g%:slider %d%:pGain
rtcon %d%:presentPosition %p%:value
rtcon %d%:moving %m%:value

:�A�N�e�B�x�[�g
rtact %c% %s% %g% %p% %m% %d%

:loop
set /p ans="�I�����܂����H (y/n)"
if not "%ans%"=="y" goto loop

rtdeact %c% %s% %g% %p% %m% %d%

:�I���irtexit�́C����������j
for %%i in (%c% %s% %g% %p% %m% %d%) do (
  rtexit %%i
)
