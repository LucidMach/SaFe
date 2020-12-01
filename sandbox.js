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
