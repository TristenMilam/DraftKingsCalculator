from urllib.request import urlopen
from bs4 import BeautifulSoup as soup
import csv


def name_fix(name):
    name_array = name.split(" ")
    first = name_array[0]
    first_array = first.split(".")
    first = ""
    for item in first_array:
        first = first + item
    return first + " " + name_array[1]


def fix_d_name(name):
    if name == "Washington Football Team":
        return "WAS Football Team"
    else:
        name_array = name.split(" ")
        return name_array[len(name_array) - 2]


soup_type = "html.parser"
player_dict = {}

#opens connection and grabs page into variable
espn_url = "https://www.fantasypros.com/nfl/projections/qb.php"
espn_client = urlopen(espn_url)
espn_whole_html = espn_client.read()
espn_client.close()

espn_soup = soup(espn_whole_html, soup_type)
temp_container = espn_soup.body.findAll("div", {"role":"main"})[0]
temp_container = temp_container.findAll("div", {"class":"mobile-table"})[0]
temp_container = temp_container.table.tbody.findAll("tr")

i = 0
while 1:
    player_stats = temp_container[i].findAll("td")
    player_name = player_stats[0].a.text
    player_proj = player_stats[10].text
    player_name = name_fix(player_name)
    if float(player_proj) > 15:
        player_dict[player_name] = player_proj
    else:
        player_dict[player_name] = player_proj
        break
    i += 1

espn_url = "https://www.fantasypros.com/nfl/projections/rb.php?scoring=PPR"
espn_client = urlopen(espn_url)
espn_whole_html = espn_client.read()
espn_client.close()

espn_soup = soup(espn_whole_html, soup_type)
temp_container = espn_soup.body.findAll("div", {"role":"main"})[0]
temp_container = temp_container.findAll("div", {"class":"mobile-table"})[0]
temp_container = temp_container.table.tbody.findAll("tr")

i = 0
while 1:
    player_stats = temp_container[i].findAll("td")
    player_name = player_stats[0].a.text
    player_proj = player_stats[8].text
    player_name = name_fix(player_name)
    if float(player_proj) > 8:
        player_dict[player_name] = player_proj
    else:
        player_dict[player_name] = player_proj
        break
    i += 1

espn_url = "https://www.fantasypros.com/nfl/projections/wr.php?scoring=PPR"
espn_client = urlopen(espn_url)
espn_whole_html = espn_client.read()
espn_client.close()

espn_soup = soup(espn_whole_html, soup_type)
temp_container = espn_soup.body.findAll("div", {"role":"main"})[0]
temp_container = temp_container.findAll("div", {"class":"mobile-table"})[0]
temp_container = temp_container.table.tbody.findAll("tr")

i = 0
while 1:
    player_stats = temp_container[i].findAll("td")
    player_name = player_stats[0].a.text
    player_proj = player_stats[8].text
    player_name = name_fix(player_name)
    if float(player_proj) > 7:
        player_dict[player_name] = player_proj
    else:
        player_dict[player_name] = player_proj
        break
    i += 1

espn_url = "https://www.fantasypros.com/nfl/projections/te.php?scoring=PPR"
espn_client = urlopen(espn_url)
espn_whole_html = espn_client.read()
espn_client.close()

espn_soup = soup(espn_whole_html, soup_type)
temp_container = espn_soup.body.findAll("div", {"role":"main"})[0]
temp_container = temp_container.findAll("div", {"class":"mobile-table"})[0]
temp_container = temp_container.table.tbody.findAll("tr")

i = 0
while 1:
    player_stats = temp_container[i].findAll("td")
    player_name = player_stats[0].a.text
    player_proj = player_stats[5].text
    player_name = name_fix(player_name)
    if float(player_proj) > 6:
        player_dict[player_name] = player_proj
    else:
        player_dict[player_name] = player_proj
        break
    i += 1

espn_url = "https://www.fantasypros.com/nfl/projections/k.php?scoring=PPR"
espn_client = urlopen(espn_url)
espn_whole_html = espn_client.read()
espn_client.close()

espn_soup = soup(espn_whole_html, soup_type)
temp_container = espn_soup.body.findAll("div", {"role":"main"})[0]
temp_container = temp_container.findAll("div", {"class":"mobile-table"})[0]
temp_container = temp_container.table.tbody.findAll("tr")

i = 0
while 1:
    player_stats = temp_container[i].findAll("td")
    player_name = player_stats[0].a.text
    player_proj = player_stats[4].text
    player_name = name_fix(player_name)
    if float(player_proj) > 7:
        player_dict[player_name] = player_proj
    else:
        player_dict[player_name] = player_proj
        break
    i += 1

espn_url = "https://www.fantasypros.com/nfl/projections/dst.php?scoring=PPR"
espn_client = urlopen(espn_url)
espn_whole_html = espn_client.read()
espn_client.close()

espn_soup = soup(espn_whole_html, soup_type)
temp_container = espn_soup.body.findAll("div", {"role":"main"})[0]
temp_container = temp_container.findAll("div", {"class":"mobile-table"})[0]
temp_container = temp_container.table.tbody.findAll("tr")

i = 0
while 1:
    player_stats = temp_container[i].findAll("td")
    player_name = player_stats[0].a.text
    player_proj = player_stats[9].text
    if player_name == "Washington Football Team":
        player_name = "WAS Football Team"
    else:
        name_array = player_name.split(" ")
        player_name = name_array[len(name_array) - 1]
    if float(player_proj) > 6:
        player_dict[player_name] = player_proj
    else:
        player_dict[player_name] = player_proj
        break
    i += 1



qbFile = open("DraftKingsCalculator/InputStats/QB.txt", 'w')
rbFile = open("DraftKingsCalculator/InputStats/RB.txt", 'w')
wrFile = open("DraftKingsCalculator/InputStats/WR.txt", 'w')
teFile = open("DraftKingsCalculator/InputStats/TE.txt", 'w')
deFile = open("DraftKingsCalculator/InputStats/DE.txt", 'w')

with open("DraftKingsCalculator/InputStats/DKSalaries.csv") as csvfile:
    file_reader = csv.reader(csvfile)
    for row in file_reader:
        if row[0] == "Position":
            continue
        else:
            name = row[2]
            cost = row[5]
            pos = row[0]
            if pos != "DST":
                name = name_fix(name)
            else:
                name = fix_d_name(name)
            if name in player_dict:
                score = player_dict[name]
                if pos == "DST":
                    if name == "WAS Football Team":
                        deFile.write("Washington D " + player_dict[name] + " " + cost + "\n")
                    else:
                        deFile.write(name + " D " + player_dict[name] + " " + cost + "\n")
                if pos == "QB":
                    qbFile.write(name + " " + score + " " + cost + "\n")
                if pos == "RB":
                    rbFile.write(name + " " + score + " " + cost + "\n")
                if pos == "WR":
                    wrFile.write(name + " " + score + " " + cost + "\n")
                if pos == "TE":
                    teFile.write(name + " " + score + " " + cost + "\n")


qbFile.close()
rbFile.close()
wrFile.close()
teFile.close()
deFile.close()