#include <iostream>
#include "DNS_QUANTUM.hpp"

int main() {
    DNS_Quantum::Qubit q1;
    DNS_Quantum::Qubit q2;

    //apply a Hadamard gate to q1
    q1.apply_gate(DNS_Quantum::HADAMARD);

    //apply a CNOT gate with q1 as control and q2 as target
    DNS_Quantum::applyCNOT(q1, q2);

    //measure both qubits
    int result1 = q1.measure();
    int result2 = q2.measure();

    std::cout << "Measurement results: " << result1 << ", " << result2 << std::endl;

    return 0;
}
