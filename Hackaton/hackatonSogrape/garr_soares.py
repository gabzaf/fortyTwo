import requests, pandas
from bs4 import BeautifulSoup
from datetime import date

MAT_ROSE = "5601012011500"
MAT_SPARK = "5601012001310"
BOLOTAS = "5601012004427"
PAPA_FIGOS = "5601012011920"

STORE_NAME = "Garrafeira Soares"
LOCATION = "Portugal"

url_search = "https://www.garrafeirasoares.pt/pt/resultado-da-pesquisa_36.html"

terms = [MAT_ROSE, MAT_SPARK, BOLOTAS, PAPA_FIGOS]

def set_original_name_gs(name):
    if name == "Vinho Rosé Mateus":
        return "Mateus Rosé Original"
    elif name == "Espumante Mateus Rosé":
        return "Mateus Sparkling Brut Rosé"
    elif name == "Vinho Tinto Trinca Bolotas":
        return "Trinca Bolotas Tinto"
    elif name == "Vinho Branco Douro Papa Figos":
        return "Papa Figos Branco"

def get_data(url, term):
    '''Get data from url: wine name, capacity, price, currency, date of scraping'''
    
    response = requests.get(url=url, params={"term": term})
    response.raise_for_status()
    soup = BeautifulSoup(response.text, "html.parser")
    content = soup.find('script').string
    url_start = content.find("'") + 1
    url_end = content.rfind("'")
    location_value = content[url_start:url_end]
    
    response = requests.get(url=location_value)
    response.raise_for_status()
    soup = BeautifulSoup(response.text, "html.parser")

    full_name = soup.find(name="div", class_="name clearfix").text.strip()
    name = " ".join(full_name.split(" ")[:-2])
    name = set_original_name_gs(name)
    capacity = " ".join(full_name.split(" ")[-2:])
    if capacity[-2:] == "Cl":
        capacity = int(capacity[:-3] + "0")
    price_full = soup.find(name="span", class_="current").text.strip()
    price = float(price_full[:-1].replace(",", "."))
    currency = price_full[-1]
    today_date = date.today().strftime("%d/%m/%Y")
    
    # print(f"Wine name: {name}")
    # print(f"Capacity: {capacity}")
    # print(f"Price: {price}")
    # print(f"Currency: {currency}")
    # print(f"Date of scraping: {today_date}")
    # print("")

    return [STORE_NAME, name, capacity, price, currency, today_date, LOCATION]

data = []

for term in terms:
    data.append(get_data(url_search, term))

df = pandas.DataFrame(data, \
columns=["Store Name", "Wine Name", "Capacity", "Price", "Currency", "Date of scraping", "Location"])
print(df)