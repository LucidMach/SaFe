#include<ESP8266WebServer.h>
#include<ESP8266WiFi.h>
ESP8266WebServer server;

#define led 2
#define fan 16

const char username[] = "Nukalas";
const char password[] = "885623277";
// const char username[] = "Lena wifi";
// const char password[] = "Yagenrobotics";
//const char username[] = "NukeAsus";
//const char password[] = "244466666";

void setup()
{
  pinMode(led,OUTPUT);
  pinMode(fan,OUTPUT);
  digitalWrite(led,1);
  digitalWrite(fan,1);
  Serial.begin(115200);
  WiFi.begin(username,password);
  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
    Serial.println("Connecting...");
  }
  IPAddress ip = WiFi.localIP();
  Serial.print("IP: ");
  Serial.println(ip);
  server.begin();
  server.on("/",SaFe);
}
void loop()
{
  server.handleClient();  
}
void SaFe()
{
  String html = R"=====(
  <!DOCTYPE html>
  <html lang="en">
    <head>
      <meta charset="UTF-8" />
      <meta name="viewport" content="width=device-width, initial-scale=1.0" />
      <title>SaFe</title>
      <link rel="preconnect" href="https://fonts.gstatic.com" />
      <link
        href="https://fonts.googleapis.com/css2?family=Poppins&display=swap"
        rel="stylesheet"
      />
      <script
        src="https://kit.fontawesome.com/192d7586f5.js"
        crossorigin="anonymous"
      ></script>
      <style>
        * {
          padding: 0;
          margin: 0;
          box-sizing: border-box;
        }
        :root {
          --theme: #35325d;
          --primary: #2a284c;
          --accent: #433d72;
        }
        body {
          font-family: "Poppins", sans-serif;
          background-color: var(--primary);
          font-size: 0.7rem;
          text-align: center;
        }
        button {
          border: none;
          border-radius: 100%;
        }
        input {
          font-family: "Poppins", sans-serif;
          margin: 10px;
          border-radius: 10px;
          padding: 5px;
          text-align: center;
          background-color: transparent;
          border: 2px solid var(--primary);
          color: white;
        }
        ::placeholder {
          color: whitesmoke;
          opacity: 1;
          text-align: center;
        }
        .container {
          background-color: var(--theme);
          max-width: 400px;
          margin: 0 auto;
          display: flex;
          flex-direction: column;
          justify-content: space-between;
          height: 91vh;
        }
        .red {
          background-color: #ff6c6c;
          color: rgb(211, 0, 0);
        }
        .green {
          background-color: rgb(101, 255, 101);
          color: rgb(0, 211, 0);
        }
        .switchbox {
          display: flex;
          flex-direction: column;
          height: 25vh;
          align-items: center;
          justify-content: space-between;
        }

        .switchbox select {
          border: 2px solid var(--primary);
          border-radius: 10px;
          padding: 5px;
          color: whitesmoke;
          background-color: var(--theme);
        }
        .switchbox input {
          width: 50px;
          margin: 0 0 0 25px;
        }
        .switch {
          font-size: 7rem;
          color: var(--primary);
          background-color: var(--theme);
          border-radius: 100%;
          box-shadow: 5px 5px;
          cursor: pointer;
        }
        .switch:active {
          box-shadow: 2.5px 2.5px;
          transform: translate(0.05px, 0.05px);
        }
        .profile {
          font-size: 2rem;
          background-color: var(--accent);
          color: var(--primary);
        }
        .signin {
          display: flex;
          flex-direction: column;
          margin: 10%;
          background-color: var(--accent);
          border-radius: 10px;
          z-index: 5;
          position: relative;
        }
        .verify {
          background-color: var(--primary);
          border: none;
          border-radius: 10px;
          padding: 5px;
          margin: 10px;
          color: white;
        }
        .johncena {
          display: none;
        }
        @media screen and (min-width: 600px) {
          .container {
            height: 95vh;
            max-width: 320px;
          }
          body {
            margin: 2.5vh 0;
          }
          .switchbox {
            height: 30vh;
          }
        }
      </style>
    </head>
    <body>
      <div class="container">
        <header>
          <div class="red">❌ Please Sign In.</div>
          <div class="green johncena">✔️ You Are Signed In</div>
        </header>
        <main>
          <form class="switchbox">
            <button name="val" class="power">
              <i class="fas fa-power-off switch"></i>
            </button>
          </form>
        </main>
        <footer>
          <div class="profile">
            <i class="fas fa-user-circle"></i>
          </div>
          <form class="signin johncena">
            <input
              type="text"
              name="user"
              placeholder="Enter Your Username"
              autocomplete="off"
            />
            <input
              type="password"
              name="pass"
              placeholder="Enter Your Password"
              autocomplete="off"
            />
            <button type="submit" class="verify">SIGN IN</button>
          </form>
        </footer>
      </div>
      <script>
        const power = document.querySelector(".power");
        const profile = document.querySelector(".profile");
        const form = document.querySelector(".signin");
        const output = document.querySelector(".switchbox");
        const red = document.querySelector(".red");
        const green = document.querySelector(".green");

        const users = [
          {
            username: "LucidMach",
            password: "lucid.Mach7",
          },
          {
            username: "SaFe",
            password: "12345678",
          },
        ];

        if (localStorage.user) {
          u = localStorage.getItem("user");
          p = localStorage.getItem("pass");
          console.log(u, p);
          success();
        }

        profile.addEventListener("click", (e) => {
          form.classList.toggle("johncena");
        });

        form.addEventListener("submit", (e) => {
          e.preventDefault();
          let auth = 0;
          users.forEach((user) => {
            console.log(auth);
            if (user.username === form.user.value && auth === 0) {
              auth = 1;
              if (user.password === form.pass.value && auth === 1) {
                success();
                localStorage.setItem("user", form.user.value);
                localStorage.setItem("pass", form.pass.value);
                auth = 1;
              } else {
                auth = 0;
              }
            } else if (auth === 0) {
              fail();
              auth = 0;
            }
          });
          form.classList.add("johncena");
        });

        power.addEventListener("click", (e) => {
          console.log("clicked");
          if (red.classList.contains("johncena")) {
            if (!output.uip.value) {
              console.log("You have not assigned any value, considering 0");
            }
            output.val.value = output.uip.value;
          }
          console.log(output.uip.value);
        });

        const success = () => {
          red.classList.add("johncena");
          green.classList.remove("johncena");
        };
        const fail = () => {
          red.classList.remove("johncena");
          green.classList.add("johncena");
        };

      </script>
    </body>
  </html>
  )=====";
  server.send(200,"text/html",html);
  if(server.arg("val") == "0")
  {
    digitalWrite(led,0);
    delay(5000);
    digitalWrite(led,1);
  }
  if(server.arg("val")=="1")
  {
    digitalWrite(fan,0);
    delay(5000);
    digitalWrite(fan,1);
  }
}
