from repository.repository import Repository
from validator.dna_validator import DNAValidator

class Controller:
    def __init__(self):
        self.__repo = Repository()

    def add_dna(self, dna_string):
        if DNAValidator.validate_dna_string(dna_string):
            self.__repo.append(dna_string)
            return True

        return False

    def filter_dna_by_subseq(self, dna_substring):
        # filter the original list
        filtered_list = []
        for lst in self.__repo.get_data():
            if dna_substring in lst:
                filtered_list.append(lst)

        # return the sorted list by string length, reversed
        filtered_list.sort(key = lambda lst: len(lst), reverse = True)
        return filtered_list

    def filter_punct3(self):
        filtered_list = []
        longest_seq_dict = {}
        for lst in self.__repo.get_data():
            cnt = 1
            cnt_max = 1
            for i in range(len(lst) - 1):
                if lst[i] == lst[i + 1]:
                    cnt += 1

                    if cnt > cnt_max:
                        cnt_max = cnt

            #print("FOR " + str(lst) + " GOT CNT MAX " + str(cnt_max))
            longest_seq_dict.update({cnt_max:lst})

        keys = longest_seq_dict.keys()
        keys = sorted(keys, reverse = True)

        for key in keys:
            filtered_list.append(longest_seq_dict[key])

        return filtered_list

    def clear_repo(self):
        self.__repo.clear()