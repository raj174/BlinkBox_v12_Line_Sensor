
class LineSensor
{
  public:
    bool available( void );// gets values from the line sensor and stores the one with a high or low state depending on the signals youve set to send
    int8_t read( void );// tells the most recent one on the line(-2 to 2, left to right, depends on orientation)
    void setMode( uint8_t mode );// tells the microcontroller the state on which it should check
    void calibrate();
  
    LineSensor( void );
    void begin(const uint8_t pin1, const uint8_t pin2, const uint8_t pin3, const uint8_t pin4, const uint8_t pin5, const uint8_t sigPin);// sets the pins of the line sensor
    void end();// stops getting values from the line sensor the line sensor 
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
      case -1:
        break;
      case 0:
        break;
      case 1:
        break;
    }
  }
}
