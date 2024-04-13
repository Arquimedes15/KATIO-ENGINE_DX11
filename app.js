const express = require('express');
const axios = require('axios');
const app = express();
const PORT = 3000;

app.use(express.json());

app.use(express.static(__dirname + '/public'))

app.post('/realizar-solicitud', (req, res) => {
    const url = 'https://www.account.suite.pe/auth/signin';
    const headers = {
        'Sec-Ch-Ua': '"Chromium";v="123", "Not:A-Brand";v="8"',
        'Accept': 'application/json, text/plain, /',
        'Content-Type': 'application/json',
        'Sec-Ch-Ua-Mobile': '?0',
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/123.0.6312.88 Safari/537.36',
        'Sec-Ch-Ua-Platform': '"Linux"',
        'Origin': 'https://www.logistico.codicore.com',
        'Sec-Fetch-Site': 'cross-site',
        'Sec-Fetch-Mode': 'cors',
        'Sec-Fetch-Dest': 'empty',
        'Referer': 'https://www.logistico.codicore.com/',
        'Accept-Encoding': 'gzip, deflate, br',
        'Accept-Language': 'en-US,en;q=0.9',
        'Priority': 'u=1, i',
    };

    axios.post(url, req.body, { headers })
        .then(response => {
            res.send(response.data);
        })
        .catch(error => {
            res.status(error.response.status).send(error.response.data);
        });
});

app.listen(PORT, () => {
    console.log(`PORT: ${PORT}`);
});
