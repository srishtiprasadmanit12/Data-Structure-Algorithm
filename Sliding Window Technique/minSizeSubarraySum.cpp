class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
          // Paso #1
        int valorMinimo = 9999999;
        int suma = 0;
        int izquierda = 0;
        int derecha = 0;

        // Paso #2
        for (derecha = 0; derecha < nums.size(); derecha++) {
            suma += nums[derecha];

            // Paso #3
            while (suma >= target) {
            // Paso #4
                valorMinimo = min(valorMinimo, derecha - izquierda + 1);
                suma -= nums[izquierda];
                izquierda++;
            }
        }

        // Paso #5
        return valorMinimo == 9999999 ? 0 : valorMinimo;

    }
};