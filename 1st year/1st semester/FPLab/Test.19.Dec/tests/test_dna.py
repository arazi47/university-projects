import unittest
from controller.controller import Controller
from repository.repository import Repository

class TestDNA(unittest.TestCase):
    def run(self):
        self.__ctrl = Controller()

        self.assertFalse(self.__ctrl.add_dna('GATAX'))
        self.assertFalse(self.__ctrl.add_dna(''))

        # 101 de caractere - invalid
        self.assertFalse(self.__ctrl.add_dna('AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA'))

        # 100 caractere - valid
        self.assertTrue(self.__ctrl.add_dna('AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA'))

        self.assertTrue(self.__ctrl.add_dna('GATCAGGCTAGCTAGTCA'))
        self.assertTrue(self.__ctrl.add_dna('GGGGGGGGGGGGGGGGAT'))


        self.__ctrl.clear_repo()
        self.__ctrl.add_dna('GATA')
        self.__ctrl.add_dna('GTAAA')
        self.__ctrl.add_dna('GTTTTTTT')

        self.assertEqual(self.__ctrl.filter_dna_by_subseq('GA'), ['GATA'])
        self.assertEqual(self.__ctrl.filter_punct3(), ['GTTTTTTT', 'GTAAA', 'GATA'])


        self.__repo = Repository()
        self.assertEqual(self.__repo.get_data(), [])
        self.__repo.append('GATA')
        self.assertEqual(self.__repo.length(), 1)
        self.assertEqual(self.__repo.get_data(), ['GATA'])
        self.__repo.clear()
        self.assertEqual(self.__repo.get_data(), [])
