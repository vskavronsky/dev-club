from Exceptions import OutOfSpaceError, PaperMaxSymbolsError


class Paper:
    def __init__(self, max_symbols: int = 4096) -> None:
        if max_symbols <= 0:
            raise PaperMaxSymbolsError('You entered incorrect max symbols for paper!')
        self._max_symbols = max_symbols

        self._symbols = 0
        self._content = ''

    @property
    def symbols(self) -> int:
        return self._symbols

    @property
    def max_symbols(self) -> int:
        return self._max_symbols

    def add_content(self, msg: str) -> None:
        start = 0

        if self._max_symbols <= 0:
            raise OutOfSpaceError('Not enough space! You used all free space on the paper!')

        new_msg = msg[start:self._max_symbols]
        self._max_symbols -= len(new_msg)
        self._content += new_msg
        self._symbols = len(self._content)

    def show(self) -> None:
        print(self._content)
