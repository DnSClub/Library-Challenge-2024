import cmath
import random

class Qubit:
    def __init__(self):
        #Initialize the qubit in the |0> state
        self.state = [complex(1, 0), complex(0, 0)]

    def apply_gate(self, gate):
        new_state = [
            gate[0] * self.state[0] + gate[1] * self.state[1],
            gate[2] * self.state[0] + gate[3] * self.state[1]
        ]
        self.state = new_state

    def measure(self):
        probability_0 = abs(self.state[0]) ** 2
        random_value = random.random()
        return 0 if random_value < probability_0 else 1

#Hadamard gate
HADAMARD = [
    1 / cmath.sqrt(2), 1 / cmath.sqrt(2),
    1 / cmath.sqrt(2), -1 / cmath.sqrt(2)
]

#Pauli-X (NOT) gate
PAULI_X = [
    complex(0, 0), complex(1, 0),
    complex(1, 0), complex(0, 0)
]

#Pauli-Y gate
PAULI_Y = [
    complex(0, 0), complex(0, -1),
    complex(0, 1), complex(0, 0)
]

#Pauli-Z gate
PAULI_Z = [
    complex(1, 0), complex(0, 0),
    complex(0, 0), complex(-1, 0)
]

def apply_CNOT(control, target):
    if control.measure() == 1:
        target.apply_gate(PAULI_X)