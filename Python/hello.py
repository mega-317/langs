import requests
from bs4 import BeautifulSoup
import pandas as pd

url = 'https://www.muscleandstrength.com/exercises'

response = requests.get(url, headers={"User-Agent": "Mozilla/5.0"})

if response.status_code == 200:
    html = response.text
    soup = BeautifulSoup(html, 'html.parser')

    href_list = []

    cell_divs = soup.find_all('div', class_='grid-x grid-margin-x grid-margin-y small-up-2 bp600-up-3 medium-up-4')

    for div in cell_divs:
        a_tags = div.find_all('a')
        for a_tag in a_tags:
            href_attribute = a_tag.get('href')
            href_list.append(href_attribute)

    print(href_list)

else :
    print(response.status_code)