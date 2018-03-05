from FileManager.file_manager import FileManager
from UserInterface.UserInterface import UserInterface


def main():
    list = FileManager.read_input("input.txt")

    if list == False:
        print("Error in reading the file, aborting!")
        return

    graph = list[0]
    edge_data = list[1]

    ui = UserInterface(graph, edge_data)
    ui.run()

if __name__ == '__main__':
    main()
