class FileManager:
    @staticmethod
    def read_puzzle():
        init_state = []
        final_state = []

        init_file_name = "PuzzleInput/2x2init"
        final_file_name = "PuzzleInput/2x2final"

        print("\t1. Read 2x2")
        print("\t2. Read 3x3")
        option = int(input(">>> "))
        if option == 2:
            init_file_name = "PuzzleInput/3x3init"
            final_file_name = "PuzzleInput/3x3final"

        try:
            with open(init_file_name) as f:
                for line in f.readlines():
                    line.strip("\n")
                    init_state.append(line.split())
        except IOError as e:
            print(e)

        try:
            with open(final_file_name) as f:
                for line in f.readlines():
                    line.strip("\n")
                    final_state.append(line.split())
        except IOError as e:
            print(e)

        return init_state, final_state