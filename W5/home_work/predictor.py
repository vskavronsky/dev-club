import requests
from bs4 import BeautifulSoup

import asyncio
from concurrent.futures import ThreadPoolExecutor

from time import time

class Parser:

    def __init__(self, url="https://www.attheraces.com/predictor", headers=None):

        self.response = requests.get(url=url, headers=headers)
        self.soup = BeautifulSoup(self.response.content, "html.parser")

        self.races = self._get_ajax()

    def _get_ajax(self):
        races = []
        for _ in self.soup.find_all('optgroup')[1:]:
            options = _.find_all('option')
            for option in options:
                href = option.get('value')
                if href and href.startswith('/ajax/'):
                    races.append(href)
        return races

class Predictor:
    def __init__(self, race_url):
        self.ajax_url = ''.join(('https://www.attheraces.com', race_url, ))
        self.race = Parser(self.ajax_url, {'X-Requested-With': 'XMLHttpRequest'})
        print(self.ajax_url)
        racecard_url = self.race.soup.find_all(
            'a',
            'button button--theme button--has-icon'
        )[0].get('href')
        self.racecard_url = ''.join(('https://www.attheraces.com', racecard_url, ))
        self.racecard = Parser(self.racecard_url, {})
        racecard_id = self.racecard.soup.find_all('a',
            'is-current tooltip'
            )[0].get('id').split('-')[-1]
        rasecard_id_url = f'https://www.attheraces.com/ajax/racecard/{racecard_id}/predictor'

        self.predict = Parser(rasecard_id_url, {'X-Requested-With': 'XMLHttpRequest'})

        self.horses_data = self._get_race_prediction()

    
    def horses(self):
        return self.predict.soup.find_all('div', 'row')

    @staticmethod
    def get_name(horse):
        return horse.find('a', 'a--plain tooltip').text

    @staticmethod
    def get_score(horse):
        return str(horse.get('data-score'))

    @staticmethod
    def get_position(horse):
        pos = horse.find('span', 'vh') or horse.find('span', 'medal__inner')
        return str(pos.text)

    def get_racecource(self):
        return self.ajax_url.split('/')[5]

    def _get_race_prediction(self):
        horses_data = []
        for horse in self.horses():
            horse_data = ','.join((
                self.get_name(horse),
                self.get_score(horse),
                self.get_position(horse),
                self.get_racecource()
                    )) + ";"
            horses_data.append(horse_data)
        print(horses_data)
        return(horses_data)


if __name__ == "__main__":
    url = "https://www.attheraces.com/predictor"
    racelist = Parser(url=url, headers={})

    async def request_ajax():
        csv_string_ = ''
        with ThreadPoolExecutor(max_workers=55) as requester:
            loop = asyncio.get_event_loop()
            tasks = [loop.run_in_executor(requester, Predictor, race) for race in racelist.races]
            for response in await asyncio.gather(*tasks):
                csv_string_ += '\n'.join(response.horses_data) + '\n'
            with open(
                    '_'.join(
                        (strftime('%y%m%d', gmtime()),
                         'predict.csv',)
                    ), 'w') as csv:
                csv.write(csv_string_)

    def get_response():
        loop = asyncio.get_event_loop()
        future = asyncio.ensure_future(request_ajax())
        loop.run_until_complete(future)
    
    start = time()     
    get_response()
    print('\n--->',time()-start,"\n")              

    start = time()
    for link in racelist.races:
        print(Predictor(link).horses_data)
    print('\n--->',time()-start,"\n") 
