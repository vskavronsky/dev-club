book = dict()

book['apple'] = 0.67
book['milk'] = 1.49
book['avocado'] = 1.69

voted = {}


def check_voter(name):
    if voted.get(name):
        print('Kick him out!')
    else:
        voted[name] = True
        print('Let him vote!')


cache = {}


def get_data_from_server(url):
    pass


def get_page(url):
    if cache.get(url):
        return cache[url]
    else:
        data = get_data_from_server(url)
        cache[url] = data
        return data


if __name__ == '__main__':
    # print(book)
    # print(book['avocado'])
    check_voter('Tom')
    check_voter('Mike')
    check_voter('Mike')
