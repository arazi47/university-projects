from user_interface.userinterface import UserInterface
from controllers.questionscontroller import QuestionsController
from controllers.filecontroller import FileController
from runtests.runtests import RunTests

def main():
    rt = RunTests()
    rt.run()

    q_ctrl = QuestionsController()
    questions = FileController.load_questions("master_question_list.txt")
    q_ctrl.add_questions(questions)

    ui = UserInterface(q_ctrl)
    ui.run()

if __name__ == "__main__":
    main()
