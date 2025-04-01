# Online Wine Price Harvesting Challenge

## Overview
This project addresses the challenge of tracking wine prices across various online stores to assist distribution and pricing strategies. It consists of two main components:
1. **Web Scraping**: Automated scripts to collect wine prices and related data from specified online stores.
2. **Dashboard**: An interactive interface to visualize and analyze the collected data.

## Web Scraping

### Features
- **Automated Data Retrieval**: Collects wine prices, capacities and other details from:
  - [Continente Online](https://www.continente.pt/)
  - [Garrafeira Soares](https://www.garrafeirasoares.pt/)
- **Data Structuring**: Outputs structured data in a Pandas DataFrame.
- **Scalability**: Designed to handle multiple stores and products.

### Data Collected
- Store Name
- Wine Name
- Capacity
- Price
- Currency
- Date of Scraping
- Location

### How to Run
1. Ensure Python 3.x is installed.
2. Install required libraries:
	- pip install requests beautifulsoup4 pandas fake_useragent


Ethical Scraping: Respect website robots.txt and avoid aggressive scraping.

Error Handling: Scripts include basic error handling for HTTP requests.
