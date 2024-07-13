#define DNS_QUBIT_SIMULATOR

#include <cmath>
#include <complex>
#include <vector>
#include <random>

namespace DNS_Quantum {

    using Complex = std::complex<double>;
    using State = std::vector<Complex>;

    class Qubit {
    public:
        State state;

        Qubit() {
            //Int the qubit in the |0> state
            state = {1, 0};
        }

        //apply a single-qubit gate represented by a 2x2 matrix
        void apply_gate(const State& gate) {
            State newState(2);
            newState[0] = gate[0] * state[0] + gate[1] * state[1];
            newState[1] = gate[2] * state[0] + gate[3] * state[1];
            state = newState;
        }

        //measure the qubit in the computational basis
        int measure() {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(0.0, 1.0);

            double probability0 = std::norm(state[0]);
            double randomValue = dis(gen);

            return (randomValue < probability0) ? 0 : 1;
        }
    };

    //Hadamard gate
    const State HADAMARD = { 1 / std::sqrt(2), 1 / std::sqrt(2), 1 / std::sqrt(2), -1 / std::sqrt(2) };

    //Pauli-X (NOT) gate
    const State PAULI_X = { 0, 1, 1, 0 };

    //Pauli-Y gate
    const State PAULI_Y = { 0, Complex(0, -1), Complex(0, 1), 0 };

    //Pauli-Z gate
    const State PAULI_Z = { 1, 0, 0, -1 };

    //apply a controlled-NOT (CNOT) gate to two qubits
    void applyCNOT(Qubit& control, Qubit& target) {
        if (control.measure() == 1) {
            target.apply_gate(PAULI_X);
        }
    }

}