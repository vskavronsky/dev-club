def standard_arg(arg):
    print(arg)
    
def pos_only_arg(arg, /):
    print(arg)
    
def kwd_only_arg(*, arg):
    print(arg)
    
def combined_example(pos_only, /, standard, *, kwd_only):
    print(pos_only, standard, kwd_only)
    
    
if __name__ == '__main__':
    print(standard_arg(1))
    print(standard_arg(arg=1))
    
    print(pos_only_arg(2))
    # print(pos_only_arg(arg=2)) TypeError
    
    # print(kwd_only_arg(3)) TypeError
    print(kwd_only_arg(arg=3))
    
    # print(combined_example(1, 2, 3)) TypeError
    print(combined_example(1, 2, kwd_only=3))
    print(combined_example(1, standard=2, kwd_only=3))
    # print(combined_example(pos_only=1, standard=2, kwd_only=3)) TypeError
    