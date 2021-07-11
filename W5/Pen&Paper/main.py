from Pen import Pen
from Paper import Paper
from Exceptions import OutOfInkError, PenCapacityError, OutOfSpaceError, PaperMaxSymbolsError

try:
    pen = Pen(12)
    paper = Paper(12)

    str1 = 'Hello '
    str2 = 'world!!!'

    pen.refill()
    pen.write(paper, str1)
    paper.show()

    pen.write(paper, str2)
    paper.show()

except(OutOfInkError, PenCapacityError, OutOfSpaceError, PaperMaxSymbolsError) as ex:
    print(ex)
