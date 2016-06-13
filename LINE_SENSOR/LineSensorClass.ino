LineSensor::LineSensor( void )
{
  _destroyed = true;
}

void LineSensor::begin( const int pin1, const int pin2, const int pin3 )
{
  _destroyed = false;
}

void LineSensor::end( void )
{
  _destroyed = true;
}

