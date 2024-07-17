import jp.go.aist.rtm.OpenRTMUtil;
import jp.go.aist.rtm.RTC.port.OutPort;
import jp.go.aist.rtm.RTC.util.DataRef;
import RTC.TimedShortSeq;
import RTC.Time;

//シリアル通信関連のライブラリを読み込む
import processing.serial.*;

//import controlP5.*;
//ControlP5[] slider;
//ControlP5 button;

//trueなら接続した状態と同じ画面になる（主に撮影用）
boolean is_simulation = false;

String bluetooth_port = "COM9";

//クラスの宣言（自作クラス）
SerialManager myPort;

float frame_rate = 100;

// データ、OutPortの変数を宣言
DataRef<TimedShortSeq> outdata;
OutPort<TimedShortSeq> outport;

// ウィンドウサイズを設定する関数
void settings() {
  size(825, 650, P3D); //window size
}

public void setup()
{
  // RTCを"jogController"というインスタンス名で生成
  OpenRTMUtil util = new OpenRTMUtil();
  util.createComponent("jogController");
  // データの初期化
  TimedShortSeq val = new TimedShortSeq();
  val.tm = new Time();
  outdata = new DataRef<TimedShortSeq>(val);
  // OutPortを"cmd"という名前で生成
  outport = util.addOutPort("cmd", outdata);

  textureMode(NORMAL);
  //ゲームパッドを検知したらサブウィンドウを開く
  if (gamepadExists())
  {
    // サブウィンドウの位置を指定する
    String[] args = {"--location=100,200","SubWindow"};  
    // サブウィンドウを開く
    SubWindow sw = new SubWindow();
    PApplet.runSketch(args, sw);
  }

  //robot       = new Robot(body, leg_num, hand_num);
  //motion_list = new MotionList();

  frameRate(frame_rate);
  //アンチエイリアス処理
  smooth();
  
  //ポートを開けるか試す
  myPort = new SerialManager(this, bluetooth_port, 57600);
  //バッファをクリア
  myPort.clear();
  delay(500);
  if (is_simulation)
  {
    println("simulation mode");
  }
}

public void draw() {

  //画面初期化
  background(0);
  textSize(30);
  textAlign(LEFT);

  //ポートが開けたかそうでないかを表記
  if (is_simulation)
  {
    //ポートが開けた場合のシミュレーション
    showText3d("Serial open: " + bluetooth_port, 20, 40);
  }
  else if (myPort.is_connected)
  {
    showText3d("Serial open: " + myPort.device_name, 20, 40);
  }
  else
  {
    showText3d("Serial failed" + myPort.device_name, 20, 40);
  }
}


class SerialManager
{
  // member variable
  Serial port;
  String device_name = "";
  boolean is_connected;

  /*** member function
  *コンストラクタ
  *SerialManager(String device_name, int baudrate)
  *int available()
  *void clear()
  *int read()
  *char readChar()
  *String readString()
  *void stop()
  *void write(int data)
  *void write(char data)
  *void write(String data)
  ***/
  
  SerialManager(PApplet Parent, String tmp_device_name, int baudrate)
  {
    print(tmp_device_name + ": ");
    try
    {
      port = new Serial(Parent, tmp_device_name, baudrate);
      println("OK");
      device_name = tmp_device_name;
      is_connected = true;
      println("serial open");
    }
    catch(Exception e)
    {
      println("failed");
      is_connected = false;
    }
  }

  int available()
  {
    if (is_connected)
    {
      return port.available();
    }
    else
    {
      return -1;
    }
  }

  void clear()
  {
    if (is_connected)
    {
      port.clear();
    }
  }

  int read()
  {
    if (is_connected)
    {
      return port.read();
    }
    else
    {
      return -1;
    }
  }

  char readChar()
  {
    if (is_connected)
    {
      return port.readChar();
    }
    else
    {
      return '0';
    }
  }

  String readString()
  {
    if (is_connected)
    {
      return port.readString();
    }
    else
    {
      return null;
    }
  }

  String readStringUntil(char c)
  {
    if (is_connected)
    {
      return port.readStringUntil(c);
    }
    else
    {
      return null;
    }
  }

  void stop()
  {
    if (is_connected)
    {
      port.stop();
    }
  }

  void write(int data)
  {
    if (is_connected)
    {
      port.write(data);
    }
  }

  void write(char data)
  {
    if (is_connected)
    {
      port.write(data);
    }
  }

  void write(String data)
  {
    if (is_connected)
    {
      port.write(data);
    }
  }
};

public class SubWindow extends PApplet
{
  // settings を必ず実装する
  void settings()
  {
    size(600, 800, P3D);
  }
  void setup()
  {
    gamepadSetup();
    smooth();
    frameRate(250);
  }
  void draw()
  {
    gamepadDraw();
  }

  void gamepadDraw()
  {
    background(0);
    textUpDate();
  }

  void textUpDate()
  {
    slider_LX = int(slider[0].getValue()*100);
    slider_LY = int(slider[1].getValue()*100);
    slider_RX = int(slider[2].getValue()*100);
    slider_RY = int(slider[3].getValue()*100);
    slider_FR = int(slider[4].getValue()*100);

    textSize(24);
    fill(240);
    textAlign(RIGHT);
    text("slider_LX U-D", 200, 40);
    text(slider_LX, 300, 40);
    text("slider_LY L-R", 200, 80);
    text(slider_LY, 300, 80);
    text("slider_RX U-D", 200, 120);
    text(slider_RX, 300, 120);
    text("slider_RY L-R", 200, 160);
    text(slider_RY, 300, 160);
    text("slider_FR +L -R", 200, 200);
    text(slider_FR, 300, 200);

    text("button_A", 200, 240);
    text(button_A, 300, 240);
    text("button_B", 200, 280);
    text(button_B, 300, 280);
    text("button_X", 200, 320);
    text(button_X, 300, 320);
    text("button_Y", 200, 360);
    text(button_Y, 300, 360);
    text("button_LB", 200, 400);
    text(button_LB, 300, 400);
    text("button_RB", 200, 440);
    text(button_RB, 300, 440);
    text("button_Back", 200, 480);
    text(button_Back, 300, 480);
    text("button_Start", 200, 520);
    text(button_Start, 300, 520);
    text("button_LA", 200, 560);
    text(button_LA, 300, 560);
    text("button_RA", 200, 600);
    text(button_RA, 300, 600);

    text("hat_XY", 200, 640);
    text(hat_XY, 300, 640);
  }
}

/***
*描画補助用関数の寄せ集め
***/

void showText3d(String str, int x, int y)
{
  pushMatrix();
  camera();
  hint(DISABLE_DEPTH_TEST);
  noLights();
  textMode(MODEL);
  text(str, x, y);
  hint(ENABLE_DEPTH_TEST);
  popMatrix();
}

//void rightHandedRotateX(float rad_angle)
//{
//  rotateZ(-rad_angle);
//}

//void rightHandedRotateY(float rad_angle)
//{
//  rotateX(-rad_angle);
//}

//void rightHandedRotateZ(float rad_angle)
//{
//  rotateY(rad_angle);
//}

//void makeLinkX(float link_length)
//{
//  stroke(50);
//  translate(0, 0, link_length / 2);
//  box(20,20,abs(link_length));
//  translate(0, 0, link_length / 2);
//}

void makeLinkY(float link_length)
{
  stroke(50);
  translate(link_length / 2, 0, 0);
  box(abs(link_length),20,20);
  translate(link_length / 2, 0, 0);
}

void makeLinkZ(float link_length)
{
  stroke(50);
  translate(0, -link_length / 2, 0);
  box(20,abs(link_length),20);
  translate(0, -link_length / 2, 0);
}

import org.gamecontrolplus.*;
import net.java.games.input.*;
import java.util.List;

ControlIO control;
ControlDevice gpad;
ControlSlider[] slider = new ControlSlider[5];
ControlButton[] button = new ControlButton[10];
ControlHat[]    hat    = new ControlHat[1];
List<ControlDevice> list;

int slider_LX, slider_LY, slider_RX, slider_RY, slider_FR;
int button_A, button_B, button_X, button_Y;
int button_LB, button_RB, button_Back, button_Start, button_LA, button_RA;
short hat_XY;
int control_counter = 0;

boolean gamepadExists()
{
  control = ControlIO.getInstance(this);
  list = control.getDevices();
  print(list);
  for (ControlDevice dev : list)
  {
    if (dev.getTypeName() == Controller.Type.GAMEPAD.toString())
    {
      gpad = dev;
      gpad.open();
      break;
    }
  }
  if (gpad == null)
  {
    println("ERROR: No available gamepad is found.");
    return false;
  }
  else
  {
    return true;
  }
}

void gamepadSetup()
{
  slider[0] = gpad.getSlider(0);  // Left  stick Up-Down
  slider[1] = gpad.getSlider(1);  // Left  stick Left-Right
  slider[2] = gpad.getSlider(2);  // Right stick Up-Down
  slider[3] = gpad.getSlider(3);  // Right stick Left-Right
  slider[4] = gpad.getSlider(4);  // Front slider +L -R

  button[0] = gpad.getButton(0);  // button_A
  button[0].plug(this, "A_ButtonPress", ControlIO.ON_PRESS);
  button[0].plug(this, "A_ButtonRelease", ControlIO.ON_RELEASE);
  button[1] = gpad.getButton(1);  // button_B
  button[1].plug(this, "B_ButtonPress", ControlIO.ON_PRESS);
  button[1].plug(this, "B_ButtonRelease", ControlIO.ON_RELEASE);
  button[2] = gpad.getButton(2);  // button_X
  button[2].plug(this, "X_ButtonPress", ControlIO.ON_PRESS);
  //button[2].plug(this, "X_ButtonRelease", ControlIO.ON_RELEASE);
  button[3] = gpad.getButton(3);  // button_Y
  button[3].plug(this, "Y_ButtonPress", ControlIO.ON_PRESS);
  //button[3].plug(this, "Y_ButtonRelease", ControlIO.ON_RELEASE);
  button[4] = gpad.getButton(4);  // button_LB
  //button[4].plug(this, "LB_ButtonPress", ControlIO.ON_PRESS);
  //button[4].plug(this, "LB_ButtonRelease", ControlIO.ON_RELEASE);
  button[5] = gpad.getButton(5);  // button_RB
  button[5].plug(this, "RB_ButtonPress", ControlIO.ON_PRESS);
  //button[5].plug(this, "RB_ButtonRelease", ControlIO.ON_RELEASE);
  button[6] = gpad.getButton(6);  // button_Back
  button[6].plug(this, "Back_ButtonPress", ControlIO.ON_PRESS);
  //button[6].plug(this, "Back_ButtonRelease", ControlIO.ON_RELEASE);
  button[7] = gpad.getButton(7);  // button_Start
  button[7].plug(this, "Start_ButtonPress", ControlIO.ON_PRESS);
  //button[7].plug(this, "Start_ButtonRelease", ControlIO.ON_RELEASE);
  button[8] = gpad.getButton(8);  // button_LA
  button[8].plug(this, "LA_ButtonPress", ControlIO.ON_PRESS);
  //button[8].plug(this, "LA_ButtonRelease", ControlIO.ON_RELEASE);
  button[9] = gpad.getButton(9);  // button_RA
  button[9].plug(this, "RA_ButtonPress", ControlIO.ON_PRESS);
  //button[9].plug(this, "RA_ButtonRelease", ControlIO.ON_RELEASE);

  hat[0] = gpad.getHat(10);       // hat_XY
  hat[0].plug(this, "HatPress", ControlIO.WHILE_PRESS);
  hat[0].plug(this, "HatRelease", ControlIO.ON_RELEASE);
}

void A_ButtonPress()
{
  button_A += 1;
  println("A");
  // データポート配列長確保
    outdata.v.data = new short[1]; // 配列の長さを設定
  outdata.v.data[0]=0;
  // データ送信
    outport.write();
  control_counter++;
}

void A_ButtonRelease()
{
  button_A -= 1;
  println("Ar");
  // データポート配列長確保
    outdata.v.data = new short[1]; // 配列の長さを設定
  outdata.v.data[0]=9;
  // データ送信
    outport.write();
}

void B_ButtonPress()
{
  button_B += 1;
  println("B");
  // データポート配列長確保
    outdata.v.data = new short[1]; // 配列の長さを設定
  outdata.v.data[0]=1;
  // データ送信
    outport.write();
  control_counter++;
}

void B_ButtonRelease()
{
  button_B -= 1;
  // データポート配列長確保
    outdata.v.data = new short[1]; // 配列の長さを設定
  outdata.v.data[0]=10;
  // データ送信
    outport.write();
  println("Br");
}

void X_ButtonPress()
{
  button_X += 1;
  println("X");
  // データポート配列長確保
    outdata.v.data = new short[1]; // 配列の長さを設定
  outdata.v.data[0]=2;
  // データ送信
    outport.write();
  control_counter++;
}

//void X_ButtonRelease()
//{
//  button_X -= 1;
//}

void Y_ButtonPress()
{
  button_Y += 1;
  println("A");
  // データポート配列長確保
    outdata.v.data = new short[1]; // 配列の長さを設定
  outdata.v.data[0]=3;
  // データ送信
    outport.write();
  control_counter++;
}

//void Y_ButtonRelease()
//{
//  button_Y -= 1;
//}

//void LB_ButtonPress()
//{
//  button_LB += 1;
//  control_counter++;
//}

//void LB_ButtonRelease()
//{
//  button_LB -= 1;
//}

void RB_ButtonPress()
{
  button_RB += 1;
  control_counter++;
}

//void RB_ButtonRelease()
//{
//  button_RB -= 1;
//}

void Back_ButtonPress()
{
  button_Back += 1;
  control_counter++;
}

//void Back_ButtonRelease()
//{
//  button_Back -= 1;
//}

void Start_ButtonPress()
{
  button_Start += 1;
  control_counter++;
}

//void Start_ButtonRelease()
//{
//  button_Start -= 1;
//}

void LA_ButtonPress()
{
  button_LA += 1;
  control_counter++;
}

//void LA_ButtonRelease()
//{
//  button_LA -= 1;
//}

void RA_ButtonPress()
{
  button_RA += 1;
  control_counter++;
}

//void RA_ButtonRelease()
//{
//  button_RA -= 1;
//}

short pred_hat_XY;
void HatPress(float x, float y)
{
  hat_XY = (short)hat[0].getValue();
  if(hat_XY==2)hat_XY=4;
  else if(hat_XY==4)hat_XY=5;
  else if(hat_XY==6)hat_XY=6;
  else if(hat_XY==8)hat_XY=7;
  else hat_XY=9;
  if (pred_hat_XY != hat_XY)
  {
    // データポート配列長確保
    outdata.v.data = new short[1]; // 配列の長さを設定
  outdata.v.data[0]=hat_XY;
  // データ送信
  
    outport.write();
    control_counter++;
  }

  pred_hat_XY = hat_XY;
}

void HatRelease(float x, float y)
{
  hat_XY = (short)hat[0].getValue();
  
  // データポート配列長確保
    outdata.v.data = new short[1]; // 配列の長さを設定
  outdata.v.data[0]=8;
  // データ送信
  
    outport.write();
}
