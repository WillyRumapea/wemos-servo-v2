const IPWemos = "192.168.100.67";
const degPosition = document.getElementById("degPosition");
const inputDeg = document.getElementById("degInput");
const submitBtnDeg = document.getElementById("submitDeg");

const getDataDeg = async () => {
  try {
    const fetchRes = await fetch(`http://${IPWemos}/getData`);

    if (!fetchRes.ok) {
      throw new Error(`HTTP error, status: ${fetchRes.status}`);
    }
    const rawData = await fetchRes.text();
    console.log("posisi: ", rawData);
    const data = parseInt(rawData) + "°";
    degPosition.innerText = data;
  } catch (err) {
    console.log("Error fetch:", err);
  }
};

const postDataDeg = async () => {
  const dataDegValue = inputDeg.value;

  if (!dataDegValue) {
    alert("Input tidak boleh kosong");
  }

  if (dataDegValue < 0 || dataDegValue > 180) {
    alert("Input harus diantara nilai 0 - 180");
  }

  try {
    const fetchRes = await fetch(`http://${IPWemos}/postData`, {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({ sudut: dataDegValue }),
    });

    if (fetchRes.ok) {
      console.log("Data berhasil terkirim ke servo");
      inputDeg.value = "";
      inputDeg.focus();
    }
  } catch (err) {
    console.log("Error fetch:", err);
  }
};

submitBtnDeg.addEventListener("click", postDataDeg);

getDataDeg();
setInterval(getDataDeg, 1000);
