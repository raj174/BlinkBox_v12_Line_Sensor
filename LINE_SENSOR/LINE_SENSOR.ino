class LineSensor
{
  public:
    bool available( void );
    int8_t read( void );
  
    LineSensor( void );
    void begin( const int pin1, const int pin2, const int pin3 );
    void end();
  private:
    boolean _destroyed;
    uint8_t _pin1;
    uint8_t _pin2;
    uint8_t _pin3;
    int8_t _lastTriggered;
};

LineSensor lineSensor;
void setup()
{
  lineSensor.begin(3, 4, 5);
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
