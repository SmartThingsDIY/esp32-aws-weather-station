'use strict';

const routes     = require('./routes/index');
const serverless = require('serverless-http');
const express    = require('express');

const app = express();
app.use(express.urlencoded({ extended: true }));
app.use(express.json());

app.use('/', routes);

module.exports.handler = serverless(app);