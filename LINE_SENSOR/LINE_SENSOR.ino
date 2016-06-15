class LineSensor
{
  public:
    bool available( void );
    int8_t read( void );
    void setMode( boolean mode );
    void calibrate();
  
    LineSensor( void );
    void begin( const uint8_t pin1, const uint8_t pin2, const uint8_t pin3, const uint8_t sigPin );
    void end();
  private:
    boolean _destroyed;
    uint8_t _pin1;
    uint8_t _pin2;
    uint8_t _pin3;
    uint8_t _sigPin;
    boolean _mode;
    int8_t _lastTriggered;
};

LineSensor lineSensor;
void setup()
{
  lineSensor.begin(3, 4, 5, 6);
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
