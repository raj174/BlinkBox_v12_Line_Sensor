
class LineSensor
{
  public:
    bool available( void );// gets values from the line sensor and gives 5 values as 1(on line) or 0.(omits 0's on the left)
    int8_t read( void );// tells the most recent one on the line(-2 to 2, left to right, depends on orientation)
    void inMode( uint8_t mode );// tells the microcontroller the mode the line sensor is using(0 for dark, 1 for normal)
    void calibrate();//Use to calibrate the line sensor
    void changeMode();//Change between dark and normal
  
    LineSensor( void );
    void begin(const uint8_t pin1, const uint8_t pin2, const uint8_t pin3, const uint8_t pin4, const uint8_t pin5, const uint8_t sigPin);
    //void begin sets the pins of the line sensor
    void end();// stops getting values from the line sensor 
  private:
    boolean _destroyed;
    uint8_t _pin1;
    uint8_t _pin2;
    uint8_t _pin3;
    uint8_t _pin4;
    uint8_t _pin5;
    uint8_t _sigPin;
    boolean _mode;
    int8_t _lastTriggered;
};

LineSensor lineSensor;
void setup()
{
  lineSensor.begin(3, 4, 5, 6, 7, 8);
  lineSensor.setMode(1);
  lineSensor.calibrate();
}

void loop()
{
  //forward
  if( lineSensor.available() )
  {
    switch( lineSensor.read() )
    {
      case 10000:
        break;
      case 11000:
        break;  
      case 01000:
        break;
      case 01100:
        break;
      case 00100:
        break;
      case 00110:
        break;
      case 00010:
        break;
      case 00011:
        break;
      case 00001:
        break;
    }
  }
}
