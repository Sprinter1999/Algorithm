import numpy as np

class State:
    def __init__(self, state, answer, direction=None, parent=None, depth=1):
        self.state = state
        self.direction = direction
        self.parent = parent
        self.answer = answer
        self.EmptyX = 0
        self.EmptyY = 0
        self.depth = depth
        self.cost = 0

    def Generate_Empty_Postion(self):
        for i in range(len(self.state)):
            for j in range(len(self.state)):
                if self.state[i][j] == ' ':
                    self.EmptyX = i
                    self.EmptyY = j

    def Generate_Next_State(self):
        #print(self.EmptyX, self.EmptyY)
        if self.direction == 'up' and self.EmptyX < len(self.state) - 1:
            s = self.state.copy()
            s[self.EmptyX, self.EmptyY] = s[self.EmptyX + 1, self.EmptyY]
            s[self.EmptyX + 1, self.EmptyY] = ' '
            Next = State(s, self.answer, 'down', self, self.depth + 1)
            return Next
        elif self.direction == 'down' and self.EmptyX > 0:
            s = self.state.copy()
            s[self.EmptyX, self.EmptyY] = s[self.EmptyX - 1, self.EmptyY]
            s[self.EmptyX - 1, self.EmptyY] = ' '
            Next = State(s, self.answer, 'up', self, self.depth + 1)
            return Next
        elif self.direction == 'left' and self.EmptyY < len(self.state) - 1:
            s = self.state.copy()
            s[self.EmptyX, self.EmptyY] = s[self.EmptyX, self.EmptyY + 1]
            s[self.EmptyX, self.EmptyY + 1] = ' '
            Next = State(s, self.answer, 'right', self, self.depth + 1)
            return Next
        elif self.direction == 'right' and self.EmptyY > 0:
            s = self.state.copy()
            s[self.EmptyX, self.EmptyY] = s[self.EmptyX, self.EmptyY - 1]
            s[self.EmptyX, self.EmptyY - 1] = ' '
            Next = State(s, self.answer, 'left', self, self.depth + 1)
            return Next
        else:
            #print("No right direction.")
            return None

    def ShowInfo(self):
        for i in range(len(self.state)):
            for j in range(len(self.state)):
                print(self.state[i, j], end=' ')
            print("\n")

    def Evalution(self):
        Count = 0
        for i in range(len(self.state)):
            for j in range(len(self.state)):
                if self.state[i, j] != self.answer[i, j]:
                    Count += 1
        self.cost = self.depth + Count

    def Evalution_2(self):
        Count = 0
        key = 0
        for i in range(len(self.state)):
            for j in range(len(self.state)):
                key = 0
                number = self.state[i,j]
                for x in range(len(self.state)):
                    for y in range(len(self.state)):
                        if(number == self.answer[x, y]):
                            Count += abs(x - i) + abs(y - j)
                            if(x == i and y == j):
                                key = 1
                            break
                if(i == len(self.state)/2 and j == len(self.state)/2):
                    Count += 3
                elif(key == 0):
                    Count += 6

        self.cost = Count
if __name__ == '__main__':
    Open = []
    CLosed = []

    OriginState = np.array([[2, 8, 3], [1, 6, 4], [7, ' ', 5]])
    TargetState = np.array([[1, 2, 3], [8, ' ', 4], [7, 6, 5]])

    state = State(OriginState, TargetState)
    state.Generate_Empty_Postion()

    Open.append(state)

    steps = 0
    path = []

    while(len(Open) > 0):
        n = Open.pop(0)
        CLosed.append(n)

        SubState = []
        direction = ''

        for i in range(4):
            if i == 0:
                direction = 'up'
            elif i == 1:
                direction = 'down'
            elif i == 2:
                direction = 'left'
            elif i == 3:
                direction = 'right'

            Substate_Try = n

            if direction == Substate_Try.direction:
                continue

            Substate_Try.direction = direction
            Substate_Try = Substate_Try.Generate_Next_State()

            if Substate_Try != None:
                Substate_Try.Generate_Empty_Postion()
                Substate_Try.Evalution_2()
                SubState.append(Substate_Try)

        for s in SubState:
            if (s.state == s.answer).all():
                while s.parent:
                    path.append(s.parent)
                    s = s.parent
                    steps += 1
                path.reverse()

        if len(path) > 0:
            break

        Open.extend(SubState)
        Open.sort(key=lambda x: x.cost)

    if(len(path) == 0):
        print('There is no right path.')
    else:
        if path:
            for node in path:
                node.ShowInfo()
                print('-------')
            for i in range(len(state.answer)):
                for j in range(len(state.answer)):
                    print(state.answer[i, j], end='  ')
                print("\n")
            print('-------')
            print("Total steps is %d" % steps)