from collections import deque
import snoop

graph = {'you': ['alice', 'bob', 'claire'], 'bob': ['mango_anuj', 'peggy'], 'alice': ['peggy'],
         'claire': ['tom_mango', 'jonny'], 'anuj': [], 'peggy': [], 'tom': [], 'jonny': []}


@snoop
def person_is_seller(subject):
    return subject.find('mango') != -1


@snoop
def search(name):
    search_queue = deque()
    search_queue += graph[name]
    searched = []
    while search_queue:
        person = search_queue.popleft()
        if person not in searched:
            if person_is_seller(person):
                print(f'{person} is a mango seller!')
                return True
            else:
                search_queue += graph[person]
                searched.append(person)
    print('There is no mango seller!')
    return False


if __name__ == '__main__':
    search('you')
