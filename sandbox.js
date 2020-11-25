const power = document.querySelector(".power");
const profile = document.querySelector(".profile");
const form = document.querySelector(".signin");
const output = document.querySelector(".switchbox");
const red = document.querySelector(".red");
const green = document.querySelector(".green");

const users = [
  {
    username: "LucidMach",
    password: "lucid.Mach@7",
  },
  {
    username: "SaFe",
    password: "12345678",
  },
];

profile.addEventListener("click", (e) => form.classList.toggle("johncena"));

form.addEventListener("submit", (e) => {
  e.preventDefault();
  users.forEach((user) => {
    if (user.username === form.user.value) {
      console.log("Y");
      if (user.password === form.pass.value) {
        console.log("Y");
        red.classList.remove("johncena");
        green.classList.add("johncena");
      }
    } else {
      red.classList.add("johncena");
      green.classList.remove("johncena");
    }
  });
  form.classList.add("johncena");
});

power.addEventListener("click", (e) => {
  // e.preventDefault();
  console.log("clicked");
  if (red.classList.contains("johncena")) {
    output.val.value = 1;
    console.log(output.val.value);
  }
});
