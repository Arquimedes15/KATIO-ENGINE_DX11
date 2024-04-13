function realizarSolicitud() {
    let em_name = document.querySelector("#name_em").value

    axios.post('http://localhost:3000/realizar-solicitud', {
        username_usuario: em_name,
        password_usuario: 'hola',
        panel: 1,
        sistema: 'logistico',
        ip: ''
    })
    .then(response => {
        console.log('Respuesta del servidor intermedio:', response.data);
        let datos = response.data
        let user = datos.data.user
        document.querySelector("#card").innerHTML = `
            <img src="${user.imgUrl}">
            <p>${user.razon_social}</p>
            <p>RUC ${user.ruc}</p>
            <p>N° ${user.idempresa}</p>
            <p>User: ${user.username_usuario}</p>
        `
    })
    .catch(error => {
        console.error('err', error);
    });
}
//admin@bloombox.com