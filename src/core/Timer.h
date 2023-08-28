class Timer
{
  private:
    uint32_t _timerTime;   // Time, elapsed by the timer
    uint32_t _timerPeriod; // Round time of the timer
    uint32_t _pauseBuffer;
    bool _isRunning;       // Current state of the timer 
    bool _isTimer;         // If true, timer will be stopped after one round
  
  public:
    Timer(uint32_t timerPeriod = 100, bool isRunning = 0, bool isTimer = 0)
    {
      _timerPeriod = timerPeriod;
      _isRunning = isRunning;
      _isTimer = isTimer;
    }

    void start() {
      _isRunning = true;
      _timerTime = millis();
    }

    void stop() {_isRunning = false;}

    void pause() 
    {
      _pauseBuffer = _timerTime % _timerPeriod;
      _isRunning = false;
    }

    void resume()
    {
      _timerTime = millis() - _pauseBuffer;
      _pauseBuffer = 0;
      _isRunning = true;
    }

    void setMode(bool isTimer) {_isTimer = isTimer;}

    bool getMode() {return _isTimer;}

    bool tick()
    {
      if(_isRunning && millis() - _timerTime >= _timerPeriod)
      {
        if(_isTimer)
        {
          _isRunning = false;
          return true;
        }
        _timerTime = millis();
        return true;
      }
      return false;
    };
};
