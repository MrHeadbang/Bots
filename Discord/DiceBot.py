import discord
from random import randrange

#Dice Rolling
async def dice(n, d, message):
        dices = []
        responseBuidler = ""
        responseBuidler += (str(message.author) + " würfelt " + str(n) + "mal einen D" + str(d))
        responseBuidler += "\n"
        for i in range(n):
            x = randrange(1, d + 1)
            dices.append(x)
            responseBuidler += ("Würfel " + str(i + 1) + " ist eine " + str(x))
            responseBuidler += "\n"
        responseBuidler += "\n"
        responseBuidler += ("Summe: " + str(sum(dices)))
        await message.channel.send(responseBuidler)

lastCommand = "1x1"
class Client(discord.Client):
    #Login
    async def on_ready(self):
        print("[Dice Bot] Started...")
    #Response
    async def on_message(self, message):
        global lastCommand
        if message.author == client.user:
            return
        if message.content == "!d help":
                await message.channel.send("Würfel Format: !d [Anzahl an Würfeln]x[Seitenanzahl der Würfel]\nBeispiele:\n3x6 (Würfelt 3mal einen 6seitigen Würfel)\n2x10 (Würfelt 2mal einen 10seitigen Würfel)\n\nSchreibe r, um den letzten Befehl zu wiederholen.")
                return
        if message.content.startswith("!d"):
            try:
                s = str(message.content).replace("!d ", "").replace(" ", "")
                if s == "r":
                    s = lastCommand
                n = int(s.split("x")[0])
                d = int(s.split("x")[1])
                lastCommand = s
                await dice(n, d, message)
            except:
                await message.channel.send("Falsches Format. Schreibe '!d help' für Hilfe.")
            
client = Client()
client.run("YOUR TOKEN")
