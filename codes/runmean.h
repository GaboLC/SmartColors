class  TrunMean
{

  public:
    //arrays that hold inputs and weights
    float* inputs;
    int n; //numero de entradas
    int last;

    TrunMean(int ninputs) {
      n = ninputs;
      inputs = new float[n];
      last = 0;
    }

    void addNew(float v) {
      inputs[last] = v;
      last = (last + 1) % n;
    }

    float getMean() {
      float sum = 0.0;
      for (int i = 0; i < n; i++) {
        sum += inputs[i];
      }
      return (sum / n);
    }

    float getMax() {
      float maxVal = 0;
      for (int i = 0; i < n; i++) {
        if (inputs[i] > maxVal) maxVal = inputs[i];
      }
      return maxVal;
    }

    float getMin() {
      float minVal = 3.4028235E+38;
      for (int i = 0; i < n; i++) {
        if (inputs[i] < minVal) minVal = inputs[i];
      }
      return minVal;
    }


};
