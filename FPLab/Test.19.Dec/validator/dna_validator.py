class DNAValidator:
    def __init__(self):
        pass

    @staticmethod
    def validate_dna_string(dna_string):
        if len(dna_string) < 1 or len(dna_string) > 100:
            return False

        for char in dna_string:
            if char not in 'ACTG':
                return False

        return True