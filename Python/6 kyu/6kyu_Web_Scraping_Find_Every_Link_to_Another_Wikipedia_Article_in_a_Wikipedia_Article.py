import requests
from bs4 import BeautifulSoup
import re

def wikiscraping(url):
    # Send a GET request to the provided URL
    response = requests.get(url)
    
    # Parse the HTML content using BeautifulSoup
    soup = BeautifulSoup(response.content, 'html.parser')
    
    # Find the div with the id 'bodyContent'
    body_content = soup.find('div', id='bodyContent')
    
    # Initialize an empty dictionary to store the article titles and URLs
    result = {}
    
    # Find all anchor tags within the 'bodyContent' div
    anchor_tags = body_content.find_all('a')
    
    # Iterate over each anchor tag
    for tag in anchor_tags:
        # Extract the href attribute
        href = tag.get('href')
        
        # Check if the href is a valid Wikipedia article link
        if href and href.startswith('/wiki/') and not any(ns in href for ns in ["User:", "Wikipedia:", "WP:", "Project:", "WT:", "Project_talk", "Wikipedia_talk:", "Image:", "Image_talk:","File:", "MediaWiki:", "Template:", "Help:", "Category:", "Portal:", "Draft:", "TimedText:", "Module:", "Special:", "Template_talk:", "Talk:", "File:", "File_talk:"]):
            # Extract the title attribute and construct the full URL
            title = tag.get('title')
            article_url = f"https://en.wikipedia.org{href}"
            
            # Add the article title and URL to the result dictionary
            result[title] = article_url
    
    return result