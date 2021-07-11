class NegativeAgeException(BaseException):
    def __init__(self, msg):
        # super().__init__()
        self.__msg = msg
        
    def what(self):
        return self.__msg
        