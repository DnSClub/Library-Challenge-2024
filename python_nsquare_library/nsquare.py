
# Library for the NxN Square tile game (15 Puzzle game)
# Summer 2024
# License: GNU AGPLv3


import os
import random


class pair:
    def __init__(self, r, c):
        self.row = r
        self.col = c


class nsquare:

    def __init__(self, size, difficulty, default=False):
        if size < 0:
            print("Error: Cannot be negative")
            exit(0)
        if size < 3:
            print("Error: min size of 3")
            exit(0)
        if size > 5:
            print("Error: limited up to size 5")
            exit(0)
        if difficulty < 1 or difficulty > 10:
            print("Error: difficulty needs to be 1-5")
            exit(0)

        # DO NOT MODIFY ------------------------------
        # Use built-in functions to access or modify.
        self.difficulty = difficulty  # 1-5
        self.size = size  # NxN
        self.default = default  # Default board (not randomized)
        self.board_size = 0  #  # Elements in game board
        self.board_key = []  # The original solution (may be more solutions)

        # Initially generated board (before user performs any moves)
        self.board_original = []
        self.empty_tile_initial = pair(3,3)  # Position of empty tile
        self.board = []  # Current board (with user moves)
        self.empty_tile = pair(3,3)  # Position of empty tile

        self.generate_initial_board()
        self.copy_board(self.board_original, 'c')
        # --------------------------------------------


    def generate_initial_board(self):
        self.board = [[0]*self.size for i in range(self.size)]
        n = 0
        for row in range(0, self.size):
            for col in range(0, self.size):
                self.board[row][col] = (n+1) % (self.size**2)
                n += 1
        self.board_size = n

        # For testing, when True, do not randomize board.
        if self.default == False:
            self.generate_game()


    # Shuffle initial board to get a game board.
    def generate_game(self):

        loops = 0
        if self.difficulty == 1:
            loops = 5
        elif self.difficulty == 2:
            loops = 10
        elif self.difficulty == 3:
            loops = 15
        elif self.difficulty == 4:
            loops = 20
        elif self.difficulty == 5:
            loops = 30
        elif self.difficulty == 6:
            loops = 50
        elif self.difficulty == 7:
            loops = 75
        elif self.difficulty == 8:
            loops = 100
        elif self.difficulty == 9:
            loops = 150
        elif self.difficulty == 10:
            loops = 200
        else:
            print("Error in generate_game()")
            exit(0)

        prev_move_reversed = ""
        for i in range(0, loops):

            possible_moves = self.get_possible_moves()

            # Remove previous move to avoid undoing a move.
            # This assumes there are always at least 2 possible moves
            # at all times in the game (which is true for this puzzle).
            moves = [i for i in possible_moves if i != prev_move_reversed]

            direction = random.choice(moves)
            if direction == 'u':
                self.move_up()
            elif direction == 'd':
                self.move_down()
            elif direction == 'l':
                self.move_left()
            elif direction == 'r':
                self.move_right()
            else:
                print("Error in generate_game()")
                exit(0)

            prev_move_reversed = self.reverse_solution([direction])[0]
            self.board_key.append(direction)

        # Solution should be steps to go from current to initial board
        self.board_key = self.reverse_solution(self.board_key)
        self.empty_tile_initial.row = self.empty_tile.row
        self.empty_tile_initial.col = self.empty_tile.col


    # Returns up down left right array where empty tile can move
    def get_possible_moves(self):
        moves = []
        # Move up
        if self.empty_tile.row > 0 and self.empty_tile.row < self.size:
            moves.append('u')
        # Move down
        if self.empty_tile.row >= 0 and self.empty_tile.row < (self.size-1):
            moves.append('d')
        # Move left
        if self.empty_tile.col > 0 and self.empty_tile.col < self.size:
            moves.append('l')
        # Move right
        if self.empty_tile.col >= 0 and self.empty_tile.col < (self.size-1):
            moves.append('r')
        if len(moves) == 0:
            print("Error in get_possible_moves()")
            exit(0)
        return moves


    def swap(self, direction):

        tmp_row = self.empty_tile.row
        tmp_col = self.empty_tile.col
        tmp_val = self.board[tmp_row][tmp_col]

        if direction == 'u':
            self.empty_tile.row -= 1
        elif direction == 'd':
            self.empty_tile.row += 1
        elif direction == 'l':
            self.empty_tile.col -= 1
        elif direction == 'r':
            self.empty_tile.col += 1
        else:
            print("Error in swap()")
            exit(0)

        self.board[tmp_row][tmp_col] = \
            self.board[self.empty_tile.row][self.empty_tile.col]
        self.board[self.empty_tile.row][self.empty_tile.col] = tmp_val


    # The Move functions assume it is possible to move in that direction.
    def move_up(self):
        self.swap('u')
    def move_down(self):
        self.swap('d')
    def move_left(self):
        self.swap('l')
    def move_right(self):
        self.swap('r')


    def get_key(self):
        return self.board_key


    # Get a (new) copy of board to input array.
    # Can copy current (c), or original board (o).
    def copy_board(self, new_board, board_type):

        new_board.clear()
        new_board.extend([[0]*self.size for i in range(self.size)])
        b = []
        if board_type == 'c':
            b = self.board
        elif board_type == 'o':
            b = self.board_original
        else:
            print("Error in copy_board()")
            exit(0)

        for row in range(0, self.size):
            for col in range(0, self.size):
                new_board[row][col] = b[row][col]


    def get_tile(self, x, y):
        return self.board[x][y]


    # Returns location of empty tile (as [row,col] array)
    def get_empty_tile(self):
        return [self.empty_tile.row, self.empty_tile.col]


    # Given a ['u', 'd', 'l', 'r'] array, reverse the solution order
    # into ['l', 'r', 'u', 'd'].
    def reverse_solution(self, s):
        solution = list(s)  # Copy
        for i in range(0, len(solution)):
            m = s[len(s)-1-i]
            if m == 'u':
                solution[i] = 'd'
            elif m == 'd':
                solution[i] = 'u'
            elif m == 'l':
                solution[i] = 'r'
            elif m == 'r':
                solution[i] = 'l'
            else:
                print("Error in reverse_solution()")
                exit(0)
        return solution


    # Check solution on original (not current) board.
    # Input solution needs to be array similar to ['u', 'd', 'l', 'r'].
    # The array is a sequence of moves to go from current board,
    # to original board (ie steps to solve the puzzle).
    # Return True if solution is correct.
    def check_solution(self, solution):

        # Temporary board (copy)
        b = nsquare(self.size, self.difficulty)
        # Replace with original board (not what user used)
        self.copy_board(b.board, 'o')
        b.empty_tile = self.empty_tile

        # Start from original (new) board.
        # Reverse all moves in solution.
        # If end up with same board as self.current, then solution
        # is correct.
        for move in solution:
            # Work on temporary board
            moves = b.get_possible_moves()
            if move in moves:
                b.swap(move)
            else:
                # Invalid move
                return False

        # Check if board matches default setup [[1,2,3,4], [5,6,7,8], ...]
        value = 0
        for row in range(0, b.size):
            for col in range(0, b.size):
                if b.board[row][col] != (value+1)%(self.size**2):
                    return False  # Not default, incorrect solution
                value += 1

        return True


    # Find tile zero
    def find_empty_tile(self):
        for i in range(0, self.size):
            for j in range(0, self.size):
                if self.board[i][j] == 0:
                    return [i, j]
        return []


    # Reset board to original values
    def reset_board(self):
        self.copy_board(self.board, 'o')
        self.empty_tile.row = self.empty_tile_initial.row
        self.empty_tile.col = self.empty_tile_initial.col


    # Returns 2D board as a string, so that it can be printed.
    # If initial=True, print the original board, else current board.
    def print_board(self, original=False):
        if original:
            b = self.board_original
        else:
            b = self.board
        max_len = len(str(self.board_size))  # Number of digits
        board_str = ""
        for i in range(0, self.size):
            for j in range(0, self.size):
                n = b[i][j]
                leading_space = max_len - len(str(n))
                board_str += " " * leading_space + str(n) + " "
            board_str += "\n"
        return board_str


if __name__ == "__main__":
    # Do nothing
    print("NSquares library")



