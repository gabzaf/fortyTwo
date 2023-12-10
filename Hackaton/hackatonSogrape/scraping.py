import requests
from bs4 import BeautifulSoup as BS

connection = requests.get("https://www.continente.pt/pesquisa/?q=mateus&start=0&srule=Continente&pmin=0.01")
data = connection.content
text = BS(data, 'html.parser')
results = text.find_all('div', {'class': 'ct-inner-tile-wrap col-inner-tile-wrap row no-gutters justify-content-center align-content-start'})
if results == 0:
	print("No wines found.")
else:
	print("Wines")
	for result in results:
		name = result.find('a', {'class': 'pwc-tile--description col-tile--description'}).text
		brand = result.find('p', {'class': 'pwc-tile--brand col-tile--brand'}).text
		capacity = result.find('p', {'class': 'pwc-tile--quantity col-tile--quantity'}).text
		price = result.find('span', {'class': 'ct-price-formatted'}).text
		print("Name:", name)
		print("Brand:", brand)
		print("Capacity:", capacity)
		print("Price:", price)
		