class LineSensor
{
  public:
    LineSensor( void );
    void begin( const int pin1, const int pin2, const int pin3 );
    void end();
  private:
    boolean _destroyed;
    const uint8_t _pin1;
    const uint8_t _pin2;
    const uint8_t _pin3;
};

void setup()
{
  // put your setup code here, to run once:

}

void loop()
{
  // put your main code here, to run repeatedly:

}
