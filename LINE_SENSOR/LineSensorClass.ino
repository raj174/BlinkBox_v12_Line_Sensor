LineSensor::LineSensor( void )
{
  _destroyed = true;
}

void LineSensor::begin( const uint8_t pin1, const uint8_t pin2, const uint8_t pin3, const uint8_t sigPin )
{
  _pin1 = pin1;
  _pin2 = pin2;
  _pin3 = pin3;
  _sigPin = sigPin;
  _lastTriggered = 0;
  _mode = 0;
  
  pinMode( _pin1, INPUT_PULLUP );
  pinMode( _pin2, INPUT_PULLUP );
  pinMode( _pin3, INPUT_PULLUP );
  pinMode( _sigPin, INPUT_PULLUP );
  
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
  
  boolean onLineState = 0;
  switch(_mode)
  {
    case 0:
      onLineState = 0;
      break;
    case 1:
      onLineState = 1;
      break;
    default:
      onLineState = 0;
  }
  if( digitalRead(_pin1) == onLineState )
  {
    _lastTriggered = -1;
  }
  else if( digitalRead(_pin2) == onLineState )
  {
    _lastTriggered = 0;
  }
  else if( digitalRead(_pin3) == onLineState )
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

void LineSensor::setMode( boolean mode )
{
  _mode = mode;
}

void LineSensor::calibrate()
{
  //pass
}
