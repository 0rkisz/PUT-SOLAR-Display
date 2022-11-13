#pragma once

#include <QDebug>
#include <QObject>
#include <QString>
#include <QSerialPort>
#include <QSerialPortInfo>

#include <string>
#include <vector>

class SerialPort : public QObject {
  Q_OBJECT

public:
  explicit SerialPort(QObject *parent = nullptr);
  void connectToSerialPort();

public slots:
  void readData();
  double getVelocity();
  double getBattery();
  double getPower();
#ifdef OLD
  bool getRightIndicator();
  bool getLeftIndicator();
  bool getLongLights();
  bool getShortLights();
  bool getAwarLights();
  QString getBMSVoltage(int index);
  bool getBMSMode();
  QString getBMSTemperature(int index);

  QString getWarningCurrent();
  QString getWarningTemp();
  QString getWarningVolt();
  QString getWarningVoltDiff();

  bool getCharging();
#endif
private:
  QSerialPort *serialportDevice;
  QSerialPortInfo serialportInfo;

#ifdef OLD

  double battery;
  bool leftIndicator;
  bool rightIndicator;
  bool shortLights;
  bool longLights;
  bool bmsMode;



  std::string warningCurrent;
  std::string warningTemp;
  std::string warningVolt;
  std::string warningVoltDiff;


  std::vector<std::string> bmsVoltages;
  std::vector<std::string> bmsTemperatures;

  bool charging;
#else
  uint16_t velocity;
  double power;
  uint16_t current;
  uint16_t battery;
  std::map<std::string, std::string> canDict;
  std::string message;

#endif
};
