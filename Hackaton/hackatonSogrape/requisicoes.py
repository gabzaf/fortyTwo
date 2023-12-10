import requests
from bs4 import BeautifulSoup

response = requests.get('https://www.continente.pt/bebidas-e-garrafeira/vinhos/')
content = response.content

site = BeautifulSoup(content, 'html.parser')

products = site.find_all('div', attrs={'class': 'ct-inner-tile-wrap col-inner-tile-wrap row no-gutters justify-content-center align-content-start'})

for product in products:
    name = product.find('div', attrs={'class': 'ct-pdp-link col-pdp-link'}).text
    capacity = product.find('div', attrs={'class': 'pwc-tile--quantity col-tile--quantity'}).text
    price = product.find('div', attrs={'class': 'prices-wrapper'}).text
    litrePrice = product.find('div', attrs={'class': 'pwc-tile--quantity col-tile--quantity'}).text
    if "Papa Figos" in name:
        print(name)
        print(capacity)
        print(price)
        print(litrePrice)
    else:
        print("Nao encontrou Papa")