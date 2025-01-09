# RTCMfromNTRIP

Tihs is Pragram what get RTCM data from NTRIP caster for ESP32.

Since it is written in a simple manner, it should be possible to port it to other devices besides ESP32.

このプログラムはESP32でRTCMデータをNTRIPキャスター（サーバー）から取得するものです。

シンプルに記述しているのでほかのマイコン等に移植が可能だと思います。

## Development Environment

Using PlatformIO, see [platfomio.ini](./platformio.ini).

Framework is arduino so this may be ArduinoIDE usable.

コンパイルと書き込みにはPlatformIOを用いています。[platfomio.ini](./platformio.ini)を参照してください。

フレームワークはarduinoなのでArduinoIDEでサンプルプログラムがコンパイルと書き込みができるはずです。

## Sample

Sample code is [here](./src/main.cpp)

You must install base64 library to use this.

Change here to your env. If ntripUser and ntripPassword is noting, here is empty.(e.g.ntripPassword = "")

サンプルは [ここ](./src/main.cpp)です。

サーバーとの接続のためにbase64ライブラリのインストールが必要です。

下記の部分を自分の環境に応じて変更してください。ntripUserとntripPasswordはなければ空で大丈夫です。(例：ntripPassword = "")

```C++
const char* ssid = "hogehoge-3F";          // WiFi SSID
const char* password = "piyopiyopswd";  // WiFi password
const char* casterHost = "111.111.11.11"; // NTRIP caster host name
const int casterPort = 2101;             // NTRIP caster port number
const char* mountpoint = "mountpoint"; // Mountpoint
const char* ntripUser = "username";      // NTIRP username
const char* ntripPassword = "passwd";  // NTRIP password
```

## LICENSE

This software is released under the MIT License, see LICENSE.
