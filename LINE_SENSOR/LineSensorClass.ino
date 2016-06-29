/*
Linesensor.begin()
LineSensor.end()
lineSensor.inMode(Put 0 or 1 depending on mode selected)
Linesensor.available()
LineSensor.read()
lineSensor.calibrate()
LineSensor.changeMode()
*/
LineSensor::LineSensor( void )
{
  _destroyed = true;
}

void LineSensor::begin( const uint8_t pin1, const uint8_t pin2, const uint8_t pin3, const uint8_t pin4, const uint8_t pin5, const uint8_t sigPin )
{
  _pin1 = pin1;
  _pin2 = pin2;
  _pin3 = pin3;
  _pin4 = pin4;
  _pin5 = pin5;
  _sigPin = sigPin;
  _lastTriggered = 0;
  _mode = -1;
  
  pinMode( _pin1, INPUT_PULLUP );
  pinMode( _pin2, INPUT_PULLUP );
  pinMode( _pin3, INPUT_PULLUP );
  pinMode( _pin4, INPUT_PULLUP );
  pinMode( _pin5, INPUT_PULLUP );
  pinMode( _sigPin, INPUT_PULLUP );
  
  _destroyed = false;
}

void LineSensor::end( void )
{
  _destroyed = true;
}

void LineSensor::inMode( uint8_t mode )
{
  _mode = mode;
}

boolean LineSensor::available()
{
  if(_destroyed == true)
  {
    return false;
  }
  
  boolean onLineState = 0;
  switch(_mode)// -1 off, 0 dark mode, 1 normal
  {
    case 0:
      onLineState = 0;
      break;
    case 1:
      onLineState = 1;
      break;
    default:
      onLineState = -1;
  }
  // Reads sensor values and assign values
  //Need to add if statements when the sensor gives 3 or more high values
  //Already done 2
  
  //Pin1
  if( digitalRead(_pin1) == onLineState )
  {
    if( digitalRead(_pin2) == onLinestate // checks if any other line next to it is on line
    {
      _lastTriggered = 11000;
    }
    else
    {
      _lastTriggered = 10000;
    }
  }
    
  //Pin2
  else if( digitalRead(_pin2) == onLineState )
  {
    if( digitalRead(_pin1) == onLinestate
    {
      _lastTriggered = 11000;
    }
    else if(digitalRead(_pin3) == onLineState)
    {
      _lastTriggered = 01100;
    }
    else
    {
      _lastTriggered = 01000;
    }
  }

  //Pin3
  else if( digitalRead(_pin3) == onLineState )
  {
    if( digitalRead(_pin2) == onLinestate
    {
      _lastTriggered = 01100;
    }
    else if(digitalRead(_pin4) == onLineState)
    {
      _lastTriggered = 00110;
    }
    else
    {
      _lastTriggered = 00100;
    }
  }

  //Pin4
  else if( digitalRead(_pin4) == onLineState )
  {
    if( digitalRead(_pin3) == onLinestate
    {
      _lastTriggered = 00110;
    }
    else if(digitalRead(_pin5) == onLineState)
    {
      _lastTriggered = 00011;
    }
    else
    {
      _lastTriggered = 00010;
    }
  }

  //Pin 5
  else if( digitalRead(_pin5) == onLineState )
  {
    if( digitalRead(_pin4) == onLinestate
    {
      _lastTriggered = 0011;
    }
    else
    {
      _lastTriggered = 00001;
    } 
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


void LineSensor::calibrate()
{
  digitalWrite(_sigPin,LOW);
  delay(100);
  digitalWrite(_sigPin,HIGH);
}


void LineSensor::changeMode()// not sure if this works, datasheet says falling edge should be in range of 1.5s
{
  digitalWrite(_sigPin,LOW);
  delay(200);
  digitalWrite(_sigPin,HIGH);
  delay(200);
  digitalWrite(_sigPin,LOW);
  digitalWrite(_sigPin,HIGH);
}

