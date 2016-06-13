LineSensor::LineSensor( void )
{
  _destroyed = true;
}

void LineSensor::begin( const int pin1, const int pin2, const int pin3 )
{
  _pin1 = pin1;
  _pin2 = pin2;
  _pin3 = pin3;
  _lastTriggered = 0;
  
  pinMode( _pin1, INPUT_PULLUP );
  pinMode( _pin2, INPUT_PULLUP );
  pinMode( _pin3, INPUT_PULLUP );
  
  _destroyed = false;
}

void LineSensor::end( void )
{
  _destroyed = true;
}

boolean LineSensor::available()
{
  if(_destroyed == true)
  {
    return false;
  }
  
  if( digitalRead(_pin1) == LOW )
  {
    _lastTriggered = -1;
  }
  else if( digitalRead(_pin2) == LOW )
  {
    _lastTriggered = 0;
  }
  else if( digitalRead(_pin3) == LOW )
  {
    _lastTriggered = 1;
  }
  else
  {
    return false;
  }

  return true;
}

int8_t LineSensor::read( void )
{
  if(_destroyed == true)
  {
    return false;
  }
  else
  {
    return _lastTriggered;
  }
}

