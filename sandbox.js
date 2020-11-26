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

profile.addEventListener("click", (e) => form.classList.toggle("johncena"));

form.addEventListener("submit", (e) => {
  e.preventDefault();
  users.forEach((user) => {
    if (user.username === form.user.value) {
      console.log("Y");
      if (user.password === form.pass.value) {
        console.log("Y");
        console.log(user.password);
        console.log(form.pass.value);
        red.classList.add("johncena");
        green.classList.remove("johncena");
      }
    }
  });
  form.classList.add("johncena");
});

power.addEventListener("click", (e) => {
  console.log("clicked");
  if (red.classList.contains("johncena")) {
    if (output.val.value === 0) {
      output.val.value = 1;
    } else {
      output.val.value = 0;
    }
  }
  console.log(output.val.value);
});
