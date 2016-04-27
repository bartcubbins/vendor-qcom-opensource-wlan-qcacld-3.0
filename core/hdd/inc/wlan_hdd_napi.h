/*
 * Copyright (c) 2015-2016 The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * This file was originally distributed by Qualcomm Atheros, Inc.
 * under proprietary terms before Copyright ownership was assigned
 * to the Linux Foundation.
 */

#ifndef __HDD_NAPI_H__
#define __HDD_NAPI_H__

#ifdef FEATURE_NAPI
/**
 * DOC: wlan_hdd_napi.h
 *
 * WLAN NAPI interface module headers
 */

/* CLD headers */
#include "hif_napi.h"
/* Linux headers */
#include <linux/netdevice.h> /* net_device */

#define HDD_NAPI_ANY (-1)

int hdd_napi_enabled(int id);
int hdd_napi_create(void);
int hdd_napi_destroy(int force);

int hdd_napi_stats(char   *buf,
		   int     max,
		   char   *indp,
		   struct qca_napi_data *napid);

/* the following triggers napi_enable/disable as required */
int hdd_napi_event(enum qca_napi_event event, void *data);

int hdd_napi_poll(struct napi_struct *napi, int budget);

struct qca_napi_data *hdd_napi_get_all(void);

#else /* ! defined(FEATURE_NAPI) */
#include "hif_napi.h"
/**
 * Stub API
 *
 */

#define HDD_NAPI_ANY (-1)

static inline int hdd_napi_enabled(int id) { return 0; }
static inline int hdd_napi_create(void) { return 0; }
static inline int hdd_napi_destroy(int force) { return 0; }
static inline int hdd_napi_stats(char *buf, int max, char *indp,
				 struct qca_napi_data *napid)
{ return 0; }
static inline int hdd_napi_event(enum qca_napi_event event, void *data)
{ return 0; }
static inline struct qca_napi_data *hdd_napi_get_all(void) { return NULL; }

#endif /* FEATURE_NAPI */

#endif /*  HDD_NAPI_H__ */
